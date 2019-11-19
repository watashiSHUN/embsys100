#include<assert.h>
#include"stack.h"

int main()
{
    int result1;
    int result2;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 9122;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt);
      
    // Assert:
    assert(result1 == -1);
    assert(testInt == 9122);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 9122;
    stack_init();
    
    // Act:
    result1 = stack_push(1024);
    result2 = stack_pop(&testInt);
    
    // Assert:
    assert(result1 == 0);
    assert(result2 == 0);
    assert(testInt == 1024);
    
    
    // *******************************************************************
    // Test3: Fill stack, then pop all items.
    // *******************************************************************
    // Arrange:
    testInt = 9122;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);                                    
    
    // Assert:
    assert(stack_pop(&testInt) == 0);
    assert(testInt == 3);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 2);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 1);

    
    // *******************************************************************
    // Test4: Fill stack, then push one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 9122;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(stack_push(4) == -1);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 3);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 2);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 1);


    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testInt = 9122;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(stack_pop(&testInt) == 0);
    assert(testInt == 3);

    assert(stack_push(1111) == 0);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 1111);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 2);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 1);

    // ***********************************************************************
    // Test6: Fill stack and retrieve all items twice
    // ***********************************************************************
    // Arrange:
    testInt = 9122;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(stack_pop(&testInt) == 0);
    assert(testInt == 3);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 2);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 1);

    assert(stack_push(4) == 0);
    assert(stack_push(5) == 0);
    assert(stack_push(6) == 0);
    
    assert(stack_push(9122) == -1);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 6);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 5);

    assert(stack_pop(&testInt) == 0);
    assert(testInt == 4);

    return 0;
}
