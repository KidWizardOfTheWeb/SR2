#ifndef HAVEGIMMICKPHANTOM_HPP
#define HAVEGIMMICKPHANTOM_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"

// total size: 0x8
class clsHaveGimmickPhantom {
public:
    clsSimpleShapePhantom* m_pcPhantom; // offset 0x0, size 0x4

    clsHaveGimmickPhantom() : m_pcPhantom(NULL) {}
    virtual ~clsHaveGimmickPhantom()
    {
        if (m_pcPhantom != NULL) {
            delete m_pcPhantom;
            m_pcPhantom = NULL;
        }
    }
    clsSimpleShapePhantom* getPhantom() { return m_pcPhantom; }
    void drawPhantom() {}
};

#endif // HAVEGIMMICKPHANTOM_HPP
