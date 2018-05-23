#include "checknum.h"
#include <QRegExp>



Checknum::Checknum()
{

}
bool Checknum::islegal(QString qs)
{
    QRegExp inputrule("^[0-9(]+.*[0-9)]$");
    return inputrule.exactMatch(qs);
}

Checknum::~Checknum()
{

}
