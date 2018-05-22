#include "checknum.h"
#include <QRegExp>



Checknum::Checknum()
{

}
bool Checknum::islegal(QString qs)
{
    QRegExp inputrule("^[1-9\(]+.*");
    return inputrule.exactMatch(qs);
}

Checknum::~Checknum()
{

}
