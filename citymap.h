#ifndef _CITYMAP_H_
#define _CITYMAP_H_
#include <string>
#include <SFML/Graphics.hpp>


#define MAX_BLOCK_AXIS 10
class cityblock {
public:
	std::string name;
	int A;
	int B;
	cityblock (std::string _name = "Empty\n",int _a=0,int _b=0){name=_name;A=_a;B=_b;}
	std::string showinfo () {return this->name+"\n"+std::to_string(A)+"::"+std::to_string(B); };
};

class citymap {
public:
	cityblock  map [MAX_BLOCK_AXIS][MAX_BLOCK_AXIS];
	const static int max_block_axis = 5; //well, shit	
        void showcityblock(sf::Vector2i);
	citymap() 
	{static cityblock CBlock;
	for (int i =0;i<MAX_BLOCK_AXIS;i++)
		for(int j=0;j<MAX_BLOCK_AXIS;j++)
			{map[i][j]=CBlock;}};
};

#endif //_CITYMAP_H_
