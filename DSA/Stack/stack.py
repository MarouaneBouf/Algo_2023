
# Could be done using OOP (better design)

def main():
    """
    It pushes the elements into the stack and pops the last element.
    """
    stack_1 = []
    while(input("Want to push, yes/no ? ") != "no"):
        push(stack_1,int(input("Enter Element: ")))
    _pop(stack_1)
    
    print(stack_1)


def is_empty(stack):
    """
    Return True if the stack is empty, otherwise return False.
    
    :param stack: The stack we want to check if it's empty
    :return: The function is_empty() is returning the length of the stack.
    """
    return len(stack) == 0


def push(stack, new_item):
    """
    Push() adds a new item to the end of the stack.
    
    :param stack: The stack to push the new item onto
    :param new_item: The item to be pushed onto the stack
    """
    stack.append(new_item)
    print("Item pushed:",new_item)




def _pop(stack):
    """
    If the stack is not empty, pop the top element off the stack
    
    :param stack: The stack to pop from
    :return: The last item in the list.
    """
    if not is_empty(stack):
        return stack.pop()



# This is a special Python construct that allows us to run the main() function by calling the script
# from the command line.
if __name__ == "__main__":
    main()
