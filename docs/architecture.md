# SR2 Architecture Notes

## Summary

The game is best described as a **hierarchical task-object framework**: an object-oriented, scheduler-driven game object system with task trees, runtime virtual hooks, manager-owned lifecycle control, and CRTP-based template helpers in several gameplay/gimmick subsystems.

This is not a strict MVC architecture. Logic, rendering submission, resource references, and state transitions are often colocated on task or object classes. The dominant abstraction is the task, not a model/view/controller split.

## Task-Based Object System

The core execution unit is `clsOOTask`, with `clsTask` as the game-facing task base.

Observed task base chain:

- `clsOOTask` owns scheduling and hierarchy state: exec flags, pause flags, priority, mode, parent task, child list, manager iterators, and task-manager map links.
- `clsTask : clsOOTask` adds game-level virtual hooks such as `execute`, `draw`, and `reset`, but no data members.
- `clsTask` has total size `0x54`, the same as `clsOOTask`.
- `clsTask` constructor argument 2 is a flag word, not an ignored placeholder: `flags & 0x7` forwards as exec flags, and `flags & 0x4` forwards as pause-enable flags unless `flags & 0x8` is set.

The standard task lifecycle pattern is:

- Construction: initialize base scheduling state and task-specific references/resources.
- `init()`: allocate or initialize resources and object state when a class has an explicit init phase.
- `execute()`: per-frame logic, state machines, AI, counters, physics updates, and child-task coordination.
- `draw()`: rendering submission or draw-side state setup.
- `reset()`: return to a baseline state without necessarily reallocating the task.
- Destructor: release owned resources and detach from manager/child structures.

## Scheduler And Ownership

`clsTaskManager` and the lower-level OO task manager infrastructure act as centralized schedulers. Tasks are selected and iterated by priority and flags rather than by MVC-style controller routes.

Important scheduling concepts:

- Priority or task type controls ordering and grouping.
- Exec flags control whether and how a task participates in update scheduling.
- Pause-enable flags control behavior while the game is paused or in pause-like states.
- Parent/child task links create a tree-like ownership model where a parent task can own or coordinate subordinate tasks.

When scaffolding or implementing task constructors, do not default to `clsTask(0, 0)` unless the disassembly proves it. The expected constructor shape is usually:

```cpp
DerivedTask(args...) : clsTask(priority, flags[, parent])
{
}
```

Use scaffold output, constructor disassembly, or existing call sites to determine the exact priority, flags, and parent.

## Obj-Task Split

Many gameplay and gimmick systems split static object behavior from dynamic task behavior.

Common roles:

- `cls..._Obj`: object/property/representation class. These often define what the object is: model data, physics shape, mass, friction, restitution, pack IDs, node/model drawing helpers, and resource-specific behavior.
- `cls..._Task`: dynamic controller and scheduled game-loop participant. These usually define what the object does: state transitions, execution, reset, draw orchestration, and child-task ownership.

The task often owns, contains, or references one or more object/model helper classes. The object class may provide physical or visual behavior while the task coordinates lifecycle and scheduling.

Example pattern:

```cpp
class clsPutGravityObj3_Obj : public clsPutGravityObj2_Obj {
public:
    virtual hkShape* getShape();
    virtual f32 getMass();
    virtual f32 getRestitution();
    virtual f32 getFriction();
    virtual s32 getPackId() const { return 2104; }
};

class clsPutGravityObj3_Task
    : public clsMultiShape,
      public clsMultiModelGimmick_Task<clsPutGravityObj3_Task,
                                       clsPutGravityObj3_Obj,
                                       clsMultiObTxModels> {
public:
    virtual void init();
    virtual void reset();
    virtual void execute();
    virtual void draw();
};
```

## CRTP And Template Frameworks

CRTP is used as a local implementation pattern, especially in shared framework helpers and gimmick systems. It is not the only architectural pattern, but it is important.

Examples:

- `clsSingleton<clsTaskManager>` is a classic CRTP-style singleton helper.
- `clsMultiModelGimmick_Task<DerivedTask, Obj, Models>` is a CRTP-style task/gimmick framework where the derived task type is passed into the base template.

This lets a shared template base statically know the concrete task, object, and model-container types. The likely goals are code reuse and compile-time dispatch for common gimmick behavior while still participating in the runtime task system through virtual `init`, `reset`, `execute`, and `draw` hooks.

Use precise terminology:

- The overall architecture is an OO task framework or hierarchical task-object framework.
- CRTP is an implementation pattern inside that architecture.
- Runtime virtual dispatch is still central; the game is not a pure static-polymorphism design.

## Physics And Rendering Integration

Physics and rendering are directly coupled to game object classes rather than isolated behind an MVC-style model layer.

Observed conventions:

- Physics-facing object classes may expose `hkShape*`, mass, restitution, and friction.
- Rendering-facing object classes may expose draw helpers, model pack IDs, model references, matrix palettes, node status arrays, and view-specific draw parameters.
- Task classes coordinate when these physics/rendering operations happen through `execute()` and `draw()`.

## Multiple Inheritance And ABI Notes

The project uses multiple inheritance in several task/object classes. Refer to the [MWCC ABI notes](https://sephdb.github.io/mwcc-abi/) when interpreting object layout, vtable placement, thunks, or virtual inheritance behavior.

Important distinction:

- `clsTask` children using normal `class Derived : public clsTask` are ordinary single non-virtual inheritance cases. They do not need virtual-base pointer adjustments.
- Multi-base classes, especially classes combining `clsTask`, singleton helpers, shape/model helpers, or CRTP bases, must be validated against DWARF and disassembly instead of assuming Itanium ABI behavior.
