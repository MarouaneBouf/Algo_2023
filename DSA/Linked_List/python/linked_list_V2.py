# A node is a data value and a pointer to the next node.
class node:
    def __init__(self, data = None, next = None) -> None:
        self.data = data
        self.next = next


class Linked_list:
    # This function initializes the linked list
    def __init__(self) -> None:
        self.head = None
    
    # Add an element at the start    
    def push(self, new_data):
        # Creating a new node and assigning the value of the new data to the new node.
        new_node = node()
        new_node.data = new_data
        new_node.next = self.head
        # Assigning the value of the new node to the variable head.
        self.head = new_node
 
 
    def append(self, item):
        # Creating a new node and assigning the data to it.
        new_node = node()
        new_node.data = item
        new_node.next = None
        # Assigning the value of the head to the variable temp.
        temp = self.head
        # Checking if the next node is empty. If it is not empty, it will assign the value of the next
        # node to the variable temp.
        while(temp.next):
            temp = temp.next
        # Assigning the value of the next node to the variable temp.
        temp.next = new_node
 
        
    # It prints the value of the variable self.   
    def display(self):
        temp = self.head
        i = 0
        while(temp != None):
            i += 1
            print(f"Element {i} is {temp.data}")
            temp = temp.next
        


def main():
    # Creating a new linked list.
    Link_Nodes = Linked_list()

    # Adding the value of 1020 and 872 to the linked list.
    Link_Nodes.push(1020)
    Link_Nodes.push(872)
    
    # Adding the value of 9921 to the linked list.
    Link_Nodes.append(9921)

    # Printing the value of the variable self.
    Link_Nodes.display()
    
    
# A way to run the main function.
if __name__ == "__main__":
    main()