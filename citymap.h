#ifndef _CITYMAP_H_
#define _CITYMAP_H_
#include <string>

#define MAX_BLOCK_AXIS 10
class cityblock {
private:
	std::string name;
	int something;
	int somethingelse;
};

class citymap {
public:
	cityblock * map [MAX_BLOCK_AXIS][MAX_BLOCK_AXIS];
	const static int max_block_axis = 5; //well, shit	
};

#endif //_CITYMAP_H_
