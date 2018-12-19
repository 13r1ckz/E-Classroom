#include "node.h" 

node *createNode(uint8_t data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    return newNode;
}

void setNextNode(node *currentNode, node *nextNode)
{
    currentNode->next = nextNode;
}

void addHeadToList(nodeList *list, node* newHead)
{
    list->head = newHead;
}

void removeHeadFromList(nodeList *list)
{
    //check if head exist
    if(list->head != NULL)
    {
        //check if there is a next node
        if(list->head->next != NULL)
        {
            node *newHead = list->head->next;
            free(list->head);
            list->head = newHead;
        }
        else
        {
            free(list->head);
            list->head = NULL;
        }
	list->size--;
    }
    else
    {
        #if PRINTF == PRINTF_EN
            printf("ERROR No head\n");
        #endif
        return;
    }

}

void addNodeToList(nodeList *list, node *newNode)
{
    //check if head exist
    if(list->head != NULL)
    {
        //check if tail exist
        if(list->tail != NULL)
        {   
            node *temp = list->tail;
            temp->next = newNode;
            list->tail = newNode;
        }
        //tail doesn't exist
        else
        {
            list->tail = newNode;
            list->head->next = list->tail;
        }
	list->size++;
    }
    //head doesn't exist
    else
    {
        addHeadToList(list, newNode);
    }
}

void addDataToList(nodeList *list, uint8_t data)
{
   node *newNode = createNode(data);
   addNodeToList(list, newNode);
}

void addStrToList(nodeList *list, char *str)
{
	int index = 0;
	while(str[index] != '\0')
	{
		addDataToList(list, str[index]);
		index++;
	}	
}

void printNode(node *currentNode)
{
    
   #if PRINTF == PRINTF_EN 
        if(currentNode != NULL)
        {
            printf("data = %d\n", currentNode->data);
        }
        else
        {
            printf("ERROR is NULL\n");
        }
   #endif
}

void printList(nodeList *list)
{
   #if PRINTF == PRINTF_EN 
        if(list->head != NULL)
        {
            node *currentNode = list->head;
            int counter = 0;
            while(currentNode != NULL)
            {
                printf("node %d = %d\n", counter, currentNode->data);
                counter++;
                currentNode = currentNode->next;
            }
        }
        else
        {
            printf("error no list\n ");
        }
   #endif
}

void printStrList(nodeList *list)
{
   #if PRINTF == PRINTF_EN 
        if(list->head != NULL)
        {
            node *currentNode = list->head;
            int counter = 0;
            while(currentNode != NULL)
            {
                printf("%c", counter, currentNode->data);
                counter++;
                currentNode = currentNode->next;
            }
            printf("\n");
        }
        else
        {
            printf("error no list\n ");
        }
   #endif
}

