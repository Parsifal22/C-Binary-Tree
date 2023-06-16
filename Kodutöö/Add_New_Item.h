bool Exist(HeaderC* pStruct4, char* newId)
{
	int i=0;
	char l1 = newId[0];
	char l2=NULL;
	Object3** ppobject;
	Object3* pobject;

	while (i < strlen(newId))
	{
		if (newId[i - 1] == ' ')
		{
			l2 = newId[i];
			break;
		}
		i++;
	}

	while (1)
	{
		if (pStruct4 == NULL || pStruct4->cBegin>l1)
		{
			return false;
		}
		
		if (pStruct4->cBegin == l1)
		{
			ppobject =(Object3**)pStruct4->ppObjects;
			break;
		}

		pStruct4 = pStruct4->pNext;

	}

	pobject=*(ppobject - 'A' + l2);

	while (1)
	{
		if(pobject == NULL)
		{
			return false;
		}

		if (!strcmp(pobject->pID, newId))
		{
			return true;
		}

		pobject = pobject->pNext;


	}

}

bool format(char* ID)
{
	int space = 0;
	int i = 0;
	char l1 = ID[0];
	char l2 = NULL;

	while (i < strlen(ID))
	{
		if ((ID[i] < 'A' || ID[i] > 'Z') && (ID[i] < 'a' || ID[i] > 'z'))
		{
			if (ID[i] == ' ' )
			{
				l2 = ID[i + 1];
				space++;
			}
			else
			{
				return 1;
			}
		}
		i++;
	}

	if (!((l1 >= 'A' || l1 <= 'Z') && (l2 >= 'A' || l2 <= 'Z')))
	{
		return 1;
	}

	if (space == 1)
	{
		return 0;
	}
	return 1;
}


Object3* initobject(char *newid, int NewCode)
{
	Object3* object;

	object = (Object3*)malloc(sizeof(Object3));
	
	int hours, minutes, seconds, i=0;
	

	
	object->pID = (char*)malloc(sizeof(char) * strlen(newid));

	object->Code = (unsigned long int)malloc(sizeof(unsigned long int));
	
	time_t now;

	object->Code = NewCode;

	strcpy(object->pID, newid);

	int t = time(&now);

	struct tm* local = localtime(&now);

	hours = local->tm_hour;         
	minutes = local->tm_min;       
	seconds = local->tm_sec;

	object->sTime1.Hour = hours;
	object->sTime1.Minute = minutes;
	object->sTime1.Second = seconds;
	object->pNext = NULL;

	return object;

}

HeaderC* initHeaderC(char newCBegin)
{
	HeaderC* newHeader = (HeaderC*)malloc(sizeof(HeaderC));

	newHeader->ppObjects = (void**)malloc(sizeof(Object3*) * 26);

	int i = 0;
	while (i < 26)
	{
		newHeader->ppObjects[i] = NULL;
		i++;
	}
	newHeader->cBegin = newCBegin;
	newHeader->pNext = NULL;
	return newHeader;
}

int InsertNewObject(HeaderC** pStruct4, char NewId[], int NewCode)
{
		Object3* newobject;

		printf("%s\n", NewId);

		bool check = format(NewId);
		
		if(check == 1)
		{
			printf("This object is invalid\n");
		}

		else
		{
			bool check2 = Exist(*pStruct4, NewId);
			
			if (check2 == 1)
			{
				printf("This object already exists\n");
			}

			else
			{
				char l2;
				char l1 = NewId[0];
				Object3** ppobject;
				int i = 0;

				while (i < strlen(NewId))
				{
					if (NewId[i - 1] == ' ')
					{
						l2 = NewId[i];
						break;
					}
					i++;
				}

				Object3* pobject = initobject(NewId, NewCode);
				HeaderC* path = *pStruct4;
				Object3** chain = NULL;

				while (1)
				{
					if (path->pNext == NULL)
					{
						HeaderC* newHeader = initHeaderC(l1);
						path->pNext = newHeader;
						chain = (Object3**)(newHeader->ppObjects + l2 - 'A');
						break;
					}
					else if (path->cBegin == l1)
					{
						chain = (Object3**)(path->ppObjects + l2 - 'A');
						break;
					}
					else if (path->cBegin > l1)
					{
						char oldcBegin = path->cBegin;
						void** oldppObjects = path->ppObjects;
						HeaderC* oldpNext = path->pNext;
						HeaderC* newold = initHeaderC(oldcBegin);
						path->pNext = newold;
						path->cBegin = l1;
						path->ppObjects = newold->ppObjects;

						newold->ppObjects = oldppObjects;
						newold->pNext = oldpNext;

						chain = (Object3**)(path->ppObjects + l2 - 'A');
						break;
					}
					else if (path->pNext->cBegin > l1)
					{
						int i = 0;
						HeaderC* oldNext = path->pNext;

						path->pNext = initHeaderC(l1);
						path->pNext->pNext = oldNext;
						
						chain = (Object3**)(path->pNext->ppObjects + l2 - 'A');
						break;
					}
					path = path->pNext;
				}
				if (*chain != NULL)
				{
					while ((Object3*)(*chain)->pNext != NULL)
					{
						*chain = (Object3*)(*chain)->pNext;
					}
					((Object3*)(*chain))->pNext = pobject;
				}
				else
				{
					*chain = pobject;
				}

				
			}
		}

		return 1;
	
}

