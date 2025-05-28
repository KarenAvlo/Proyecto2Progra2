#include "objectBase.h"

ostream& operator<<(ostream& out, const Base& obj) {
	out << obj.toString();
	return out;
}
