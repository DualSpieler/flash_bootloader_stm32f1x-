#include <stdint.h>
#include "../api/queue_static.h"


uint8_t IsQueueFull(MyQueueStatic* MyQueue)
{
	uint8_t retVal = 0;

	if (MyQueue->front == ((MyQueue->rear + 1) % QUEUE_STATIC_BUFFER_SIZE))
	{
		retVal = 1;
	}

	return retVal;
}

uint8_t MyStaticQueue_IsQueueEmpty(MyQueueStatic* MyQueue)
{
	uint8_t retVal = 0;

	if ((MyQueue->front == -1) && (MyQueue->rear == -1))
	{
		retVal = 1;
	}

	return retVal;
}

void MyStaticQueue_Init(MyQueueStatic* MyQueue)
{
	/*< reset front and rear value */
	MyQueue->front = -1;
	MyQueue->rear  = -1;

	/*< reset buffer value to 0 */
#if 0
	memset(MyQueue->Buffer, 0, QUEUE_STATIC_BUFFER_SIZE);
#else
	uint16_t i;

	for (i = 0; i < QUEUE_STATIC_BUFFER_SIZE; i++)
	{
		MyQueue->Buffer[i] = 0;
	}
#endif
}

uint8_t MyStaticQueue_EnQueue(MyQueueStatic* MyQueue, QUEUE_STATIC_ELEMENT_TYPE Element)
{
	uint8_t retVal = 1;

	if (!IsQueueFull(MyQueue))
	{
		if (MyStaticQueue_IsQueueEmpty(MyQueue))
		{
			MyQueue->front = 0;
			MyQueue->rear = 0;
		}
		else
		{
			MyQueue->rear = (MyQueue->rear + 1) % QUEUE_STATIC_BUFFER_SIZE;
		}

		MyQueue->Buffer[MyQueue->rear] = Element;
	}
	else
	{
		retVal = 0;
	}

	return retVal;
}

uint8_t MyStaticQueue_DeQueue(MyQueueStatic* MyQueue, QUEUE_STATIC_ELEMENT_TYPE* Element)
{
	uint8_t retVal = 1;

	if (!MyStaticQueue_IsQueueEmpty(MyQueue))
	{
		*Element = MyQueue->Buffer[MyQueue->front];

		if (MyQueue->front == MyQueue->rear)
		{
			MyQueue->front = -1;
			MyQueue->rear = -1;
		}
		else
		{
			MyQueue->front = (MyQueue->front + 1) % QUEUE_STATIC_BUFFER_SIZE;
		}
		
	}
	else
	{
		retVal = 0;
	}

	return retVal;
}


uint8_t MyStaticQueue_Peek(MyQueueStatic* MyQueue, QUEUE_STATIC_ELEMENT_TYPE* Element)
{
	uint8_t retVal = 1;

	if (!MyStaticQueue_IsQueueEmpty(MyQueue))
	{
		*Element = MyQueue->Buffer[MyQueue->front];
	}
	else
	{
		retVal = 0;
	}

	return retVal;
}

#if 0
void MyStaticQueue_Traverse(MyQueueStatic* MyQueue)
{
	int16_t i = MyQueue->front;

	if (IsQueueEmpty(MyQueue))
	{
		printf("queue is empty...\n");
	}

	else if (i == MyQueue->rear)
	{
		printf("queue index : [%d], queue element : [%d]\n", i, MyQueue->Buffer[i]);
	}

	else
	{
		do
		{
			printf("queue index : [%d], queue element : [%d]\n", i, MyQueue->Buffer[i]);

			i = (i + 1) % QUEUE_STATIC_BUFFER_SIZE;
		} while (i != MyQueue->rear);

		printf("queue index : [%d], queue element : [%d]\n", i, MyQueue->Buffer[i]);
	}
}
#endif
