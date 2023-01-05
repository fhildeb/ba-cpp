class Reihe {

	protected: 
		int basis;
	public:	
		Reihe(int b) : basis(b){};
		Reihe(){};

	int operator[] (int i) 
	{
		return basis*i;
	};

	Reihe operator+ (Reihe& r)
	{
		return Reihe(basis+r.basis);
	};

	void* operator new[] (size_t s)
	{
		reihe* p_reihen = (Reihe*)new unsigned char[s];
		
		for(int i=0; i < s/sizeof(Reihe);i++)
			p_reihen[i].basis = i;
		return p_reihen;
	};
};