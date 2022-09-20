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
        
    # Delete the first element of the linked list
    def delete_1(self):
        self.head = self.head.next
    
    # Delete the last element from the linked list    
    def delete_2(self):
        temp = self.head
        while(temp.next.next != None):
            temp = temp.next
        temp.next = None
        
    # Delete a specific node from the linked list byt its data
    def delete_3(self, cible):
        temp = self.head
        while(temp.next.data != cible):
            temp = temp.next
        temp.next = temp.next.next
        
        
    def insert(self, new_item, cible):
        """
        It creates a new node, sets its data to the new item, and then finds the node with the data
        equal to the cible, and then sets the new node's next to the cible's next, and then sets the
        cible's next to the new node
        
        :param new_item: the item to be inserted
        :param cible: the item you want to insert after
        """
        new_node = node()
        new_node.data = new_item
        temp = self.head
        while(temp.data != cible):
            temp = temp.next
        new_node.next = temp.next
        temp.next = new_node
 
        
    # It prints the value of the variable self.   
    def display(self):
        temp = self.head
        i = 0
        while(temp != None):
            i += 1
            print(f"Element {i} is {temp.data}")
            temp = temp.next
         
    # Reversing the linked list        
    def reverse(self):
        current = self.head
        following = self.head
        previous = None
        while(current is not None):
            following = following.next
            current.next = previous
            previous = current
            current = following
        self.head = previous
        
    '''
    def remove(self, item):
        temp = self.head
        if self.head.data == item:
            return None
        try:
            while(temp.next.data != item):
                temp = temp.next
            temp.next = temp.next.next
        except Exception:
            print("Don't choose edge elements!")
            self.head
    '''

def main():
    # Creating a new linked list.
    Link_Nodes = Linked_list()

    # Adding the value of 1020 and 872 to the linked list.
    Link_Nodes.push(1020)
    Link_Nodes.push(872)
    
    # Adding the value of 9921 to the linked list.
    Link_Nodes.append(9921)
    
    Link_Nodes.insert(20,872)
    
    print("Before deleting the first element")
    # Printing the value of the variable self.
    Link_Nodes.display()
    
    print("After deleting the first element")
    # Deleting the first element
    Link_Nodes.delete_1()
    # Deleting the last element
    Link_Nodes.delete_2()
    # Deleting an element at a specific position
    Link_Nodes.delete_3(1020)
    
    Link_Nodes.display()
    
    
# A way to run the main function.
if __name__ == "__main__":
    main()