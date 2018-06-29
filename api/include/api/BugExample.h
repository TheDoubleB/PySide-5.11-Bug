#ifndef BugExample_H
#define BugExample_H

#include <QMap>
#include <QList>

class BugExampleClass
{
	public:
		struct Vector3f
		{
			float x;
			float y;
			float z;
		};

	public:
		BugExampleClass();
		QList<QList<float>> method1();
		QMap<int, QList<float>> method2();
		// NOTE: `method3()` works with PySide/Shiboken 5.9 but does not work with 5.11. On 5.11, it produces the following error while running `shiboken2`:
		//     (BugExample) Could not find type '::QList_0' for use in 'toPython' conversion: Cannot find type "QList_0" for "QList_0".
		//     Make sure to use the full C++ name, e.g. 'Namespace::Class'.
		// QMap<int, QList<QList<float>>> method3();
		QList<QList<Vector3f>> method4();
};

#endif // BugExample_H
