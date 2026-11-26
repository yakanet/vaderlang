#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 3780u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 2007u;
	} else {
		if (!(l0 == INT32_C(2))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 3722u;
	}
	return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 3748u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 2825u;
	} else if (l0 == INT32_C(2)) {
		l1 = 2309u;
	} else if (l0 == INT32_C(3)) {
		l1 = 3720u;
	} else {
		if (!(l0 == INT32_C(4))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 2108u;
	}
	return l1;
}
