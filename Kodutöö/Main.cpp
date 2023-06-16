#include "stdio.h"

#pragma warning ( disable : 4996 )
#pragma warning ( disable : 6308 )
#pragma warning ( disable : 6001 )
#pragma warning ( disable : 6031 )
#include "string.h"
#include "malloc.h"
#include "time.h"
#include "DateTime.h"
#include "Objects.h"
#include "Headers.h"
#include "Structs.h"
#include "stdlib.h"

#include "Print.h"
#include "Add_New_Item.h"
#include "Remove_item.h"






int main()
{

	HeaderC* pointer = GetStruct4(3,35);

	

	char Matrix[7][6] =
	{
		"Zz Zz",
		"Ab Aa",
		"Dx Gz",
		"Ee Ee",
		"Dx Ga",
		"Fa_Fa",	
		"Fg",
	};

	/*
	{
	{'D','x',' ','G','z'},
	{'D','x',' ','G','a'},
	{'D','b',' ','A','a'},
	{'D','k',' ','Z','a'},
	{'D','r',' ','W','a'},
	{'A','a',' ','A','a'},
	{'A','b',' ','B','a'},
	{'Z','a',' ','A','a'},
	{'Z','a',' ','B','a'},
	{'Z','a',' ','A','b'},
	{'W','x',' ','X','a'},
	{'z','b',' ','K','k'},
	{'Z','c',' ','c','a'},
	{'Z','B',' ','k','k'},
	{' ',' ',' ','F','a'},
	{'F','a','_','F','a'},
	};
	*/
	int NewCode = 333333333;
	
	int i = 0;
	int r;
	while (i<7)
	{
		r= InsertNewObject(&pointer, Matrix[i], NewCode);

		i++;
	}

	PrintObjects(pointer);
}
