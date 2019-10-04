void extend() {
	if (layout == 1) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < (wx1 + wx2)*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 2; }
		if (mpo1 >(wx1 + wx2)*csize && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 3; }
		if (mpo1 > 0 && mpo1 < wx3*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 4; }
		if (mpo1 > wx3*csize && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 5; }
	}
	if (layout == 2) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < (wx1 + wx2)*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 2; }
		if (mpo1 >(wx1 + wx2)*csize && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 3; }
		if (mpo1 > 0 && mpo1 < wx3*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 4; }
		if (mpo1 > wx3*csize && mpo1 < (wx3 + wx4)*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 5; }
		if (mpo1 >(wx3 + wx4)*csize && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 6; }
	}
	if (layout == 3) {
		if (mpo1 > 0 && mpo1 <csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 > 0 && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 2; }
	}
	if (layout == 4) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < csize2 - 25) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>52 && mpo2 <csize2 - 25) { curwin = 2; }
	}
	if (layout == 5) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 2; }
		if (mpo1 > 0 && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 3; }
	}
	if (layout == 6) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < csize2 - 25) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 2; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 3; }
	}
	if (layout == 7) {
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>52 && mpo2 < csize2 - 25) { curwin = 3; }
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 2; }
	}
	if (layout == 8) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < csize2 - 25) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 2; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <((wy1 + wy2)*(csize2 - 76) + 52)) { curwin = 3; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>((wy1 + wy2)*(csize2 - 76) + 52) && mpo2 <csize2 - 25) { curwin = 4; }
	}
	if (layout == 9) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < csize2 - 25) { curwin = 2; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < csize2 - 25) { curwin = 3; }
		if (mpo1 > 0 && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
	}
	if (layout == 10) {
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>52 && mpo2 < csize2 - 25) { curwin = 4; }
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 >0 && mpo1 < wx1*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <((wy1 + wy2)*(csize2 - 76) + 52)) { curwin = 2; }
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>((wy1 + wy2)*(csize2 - 76) + 52) && mpo2 <csize2 - 25) { curwin = 3; }
	}
	if (layout == 11) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < (wx1 + wx2)*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 2; }
		if (mpo1 >(wx1 + wx2)*csize && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 3; }
		if (mpo1 > 0 && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 4; }
	}
	if (layout == 12) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < csize2 - 25) { curwin = 2; }
		if (mpo1 > wx1*csize && mpo1 < (wx1 + wx2)*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < csize2 - 25) { curwin = 3; }
		if (mpo1 >(wx1 + wx2)*csize && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 < csize2 - 25) { curwin = 4; }
		if (mpo1 > 0 && mpo1 < csize&&mpo2>52 && mpo2 <(wy1*(csize2 - 76)) + 52) { curwin = 1; }
	}
	if (layout == 13) {
		if (mpo1 > 0 && mpo1 < wx1*csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 1; }
		if (mpo1 > wx1*csize && mpo1 < csize&&mpo2>52 && mpo2 < (wy1*(csize2 - 76)) + 52) { curwin = 2; }
		if (mpo1 > 0 && mpo1 < wx2*csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 3; }
		if (mpo1 > wx2*csize && mpo1 < csize&&mpo2>(wy1*(csize2 - 76)) + 52 && mpo2 <csize2 - 25) { curwin = 4; }
	}
	if (mpo2 < 52) { curwin = 0;  }
	if (mpo2 > csize2-25) { curwin = 0; }
}

void mause() {

}