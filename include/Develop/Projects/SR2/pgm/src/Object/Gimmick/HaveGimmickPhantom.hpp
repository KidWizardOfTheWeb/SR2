#ifndef HAVEGIMMICKPHANTOM_HPP
#define HAVEGIMMICKPHANTOM_HPP

class clsSimpleShapePhantom;

// total size: 0x8
class clsHaveGimmickPhantom {
public:
    virtual ~clsHaveGimmickPhantom() {}
    virtual void destroyCollision() {}
    virtual void updateSetEditorCollision() {}
    clsSimpleShapePhantom* m_pcPhantom; // offset 0x4, size 0x4 (DWARF shows 0x0: vtptr implicit)

    clsSimpleShapePhantom* getPhantom() { return m_pcPhantom; }
    void drawPhantom() {}
};

#endif // HAVEGIMMICKPHANTOM_HPP
