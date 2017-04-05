#ifndef _CITYMAP_H_
#define _CITYMAP_H_
#include <string>
class cityblock {
private:
	std::string name;
	int something;
	int somethingelse;
};

class citymap {
public:
	cityblock * map [5][5];
	const static int max_block_axis = 5; //well, shit	
};

#endif //_CITYMAP_H_
