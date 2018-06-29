#include <api/BugExample.h>

BugExampleClass::BugExampleClass()
{

}

QList<QList<float>> BugExampleClass::method1()
{
    return QList<QList<float>>();
}

QMap<int, QList<float>> BugExampleClass::method2()
{
    return QMap<int, QList<float>>();
}

// QMap<int, QList<QList<float>>> BugExampleClass::method3()
// {
    // return QMap<int, QList<QList<float>>>();
// }

QList<QList<BugExampleClass::Vector3f>> BugExampleClass::method4()
{
    return QList<QList<Vector3f>>();
}
