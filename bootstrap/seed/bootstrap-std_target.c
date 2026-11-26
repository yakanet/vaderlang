#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 3772u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 2004u;
	} else {
		if (!(l0 == INT32_C(2))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 3714u;
	}
	return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 3740u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 2822u;
	} else if (l0 == INT32_C(2)) {
		l1 = 2306u;
	} else if (l0 == INT32_C(3)) {
		l1 = 3712u;
	} else {
		if (!(l0 == INT32_C(4))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 2105u;
	}
	return l1;
}
