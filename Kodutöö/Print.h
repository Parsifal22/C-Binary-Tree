#pragma once




void PrintObjects(HeaderC* pointer)
{  
	
	HeaderC* header = pointer;
	int i = 0;
	int N = 1;
	while (header != NULL)
	{
		printf("This Headers is %c\n", header->cBegin);
		while (i < 26)
		{
			Object3* object = (Object3*)(*(header->ppObjects + i));

			while (object != NULL)
			{
				printf("%d) %s %lu %02d: %02d : %02d\n", N, object->pID, object->Code, object->sTime1.Hour, object->sTime1.Minute, object->sTime1.Second);
				N++;
				object = object->pNext;
			}

			i++;
		}

		i = 0;
		header = header->pNext;
	}
}