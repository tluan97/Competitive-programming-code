
struct random {
	LL rand16(){
		return rand() & ((1LL<<16)-1);
	}
	LL rand32(){
		return rand16()<<16 | rand16();
	}
	LL rand64(){
		return rand32()<<32 | rand32();
	}
};
