void deleteObject(Object3 *object, Object3** prevObject)
{
	(*prevObject = object->pNext);
	free(object->pID);
	free(object);
}

void deleteHeader(HeaderC *header, HeaderC **prevHeader)
{
	if (*prevHeader == NULL)
	{
		(*prevHeader)->pNext = header->pNext;
	}
	else
	{
		*prevHeader = header->pNext;
	}
	free(header->ppObjects);
	free(header);
}


Object3* RemoveExistingObject(HeaderC** pStruct4, char pexistID[])
{
	if (!Exist(*pStruct4,pexistID))
	{
		printf("This object %s doesn't exist\n", pexistID);
		return 0;
	}
	
	HeaderC* header = *pStruct4;
	HeaderC* prevHeader = NULL;
	Object3* returnable = NULL;
	Object3* object = NULL;
	Object3* prevObject;
	char l1 = pexistID[0];
	char l2 = NULL;
	int i = 0;
	int onumber = 0;

	while (i < strlen(pexistID))
	{
		if (pexistID[i - 1] == ' ')
	{
			l2 = pexistID[i];
			break;
	}
		i++;
	}

	while (1)
	{
		if (header->cBegin == l1)
		{
			printf("test1");
			break;
		}
		prevHeader = header;
		header = header->pNext;
	}

	i = 0;
	prevObject = (Object3*)*((*pStruct4)->ppObjects + l2 - 'A');

	while (i<26)
	{
		Object3* tempObject = (Object3*)*(header->ppObjects+i);

		if (tempObject != NULL)
		{
			printf("test2");
			onumber++;
			tempObject = tempObject->pNext;

		}
		i++;
	}

	object = (Object3*)*((*pStruct4)->ppObjects + l2 - 'A');
	while (strcmp((object->pID), pexistID))
	{
		object = object->pNext;
		prevObject = object;
	}

	returnable = object;
	printf("test3");
	if(object->pNext==NULL && object->pNext!=NULL)
	{
		prevObject->pNext = NULL;
	}
	else if (object->pNext != NULL && prevObject != NULL)
	{
		prevObject->pNext = object->pNext;
		object->pNext = NULL;
	}
	else if(prevObject == object && object->pNext != NULL)
	{
		*((*pStruct4)->ppObjects + l2 - 'A') = object->pNext;
		printf("test4");
		if (header->pNext == NULL && prevHeader->pNext != NULL)
		{
			prevHeader->pNext = NULL;
			deleteHeader(header, &prevHeader);
		}
		
		else if (header->pNext != NULL && prevHeader->pNext != NULL)
		{
			prevHeader->pNext = header->pNext;
			header->pNext = NULL;
			deleteHeader(header, &prevHeader);
		}
		
		else if (header->pNext != NULL && prevHeader == header)
		{
			*pStruct4 = header->pNext;
			deleteHeader(header, &prevHeader);
		}
	}
	printf("test5");
	return returnable;



	/*while (1)
	{
		if (header->cBegin == l2)
		{

			Object3* objectPointer = (Object3*)(header->ppObjects + onumber);
			Object3* oldPointer = objectPointer;
						
			while (1)
			{

				if (strcmp(objectPointer->pID, pexistID) == 0)
				{
					res = objectPointer; 
					if (onumber == 0 && objectPointer->pNext == NULL)
					{
									
						if (hnumber == 0 && header->pNext == NULL)
						{
							init = NULL;
							free(header);
						}
						else if ( hnumber == 0 && header->pNext != NULL)
						{
							init = header->pNext;
							free(header);
						}
						else
						{
							oldheader->pNext = header->pNext;
							free(header);
						}
					}
					else
					{
						oldPointer->pNext = objectPointer->pNext;
					}
					break;
				}
				else
				{
					onumber++;
					oldPointer = objectPointer;
					objectPointer = objectPointer->pNext;
				}
			}
			break;
		}
		else
		{
			hnumber++;
			oldheader = header;
			header = header->pNext;
		}
	}
	return res;*/
}
