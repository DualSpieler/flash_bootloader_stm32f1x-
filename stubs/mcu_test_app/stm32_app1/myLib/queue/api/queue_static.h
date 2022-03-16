#ifndef __QUEUE_STATIC_H__
#define __QUEUE_STATIC_H__

/*********************************************************************************************************************
 *							                       Macro definitions
 ********************************************************************************************************************/

#define QUEUE_STATIC_ELEMENT_TYPE  uint8_t
#define QUEUE_STATIC_BUFFER_SIZE   0X0AU

 /*********************************************************************************************************************
  *							                          typedefs
  ********************************************************************************************************************/

typedef struct MyQueueStatic_Tag
{
	int16_t front;
	int16_t rear;
	QUEUE_STATIC_ELEMENT_TYPE Buffer[QUEUE_STATIC_BUFFER_SIZE];
}MyQueueStatic;

 /*********************************************************************************************************************
  *							                       Functions Declarations
  ********************************************************************************************************************/

  /**
   *  @brief : This function is used to reset/initialize the structure
   *  @param : 
   *  @return: MySingleList. dynamically created Pointer to a head node.
   */

extern void MyStaticQueue_Init(MyQueueStatic *MyQueue);

/**
 *  @brief : This function is used to enqueue an element to the queue
 *  @param : MyQueueStatic*, QUEUE_STATIC_ELEMENT_TYPE
 *  @return: uint8_t - Status of Enqueue operation
 */

extern uint8_t MyStaticQueue_EnQueue(MyQueueStatic* MyQueue, QUEUE_STATIC_ELEMENT_TYPE Element);

/**
 *  @brief : This function is used to dequeue element from the list.
 *  @param : MyQueueStatic*, QUEUE_STATIC_ELEMENT_TYPE*
 *  @return: uint8_t - Status of Dequeue operation
 */

extern uint8_t MyStaticQueue_DeQueue(MyQueueStatic* MyQueue, QUEUE_STATIC_ELEMENT_TYPE* Element);

/**
 *  @brief : This function is used to get the peek element of the queue
 *  @param : MyQueueStatic*, QUEUE_STATIC_ELEMENT_TYPE*
 *  @return: uint8_t - Status of peek operation
 */

extern uint8_t MyStaticQueue_Peek(MyQueueStatic* MyQueue, QUEUE_STATIC_ELEMENT_TYPE* Element);

/**
 *  @brief : This function is used to know whether the queue is empty or not
 *  @param : MyQueueStatic*
 *  @return: uint8_t - 0 - empty, 1 - not empty
 */

extern uint8_t MyStaticQueue_IsQueueEmpty(MyQueueStatic* MyQueue);

#if 0
/**
 *  @brief : This function is used to travese the queue.
 *  @param : MyQueueStatic*
 *  @return: void
 */

extern void MyStaticQueue_Traverse(MyQueueStatic* MyQueue);
#endif


#endif //__QUEUE_STATIC_H__
