import math
class State:
    
    
    # Initializing the Eight Puzzle by the given size, fringe and explored list
    # fringe = List of expanded states
    # explored = List of visited states
   
    
    def __init__(self,value,level,fval):
        self.value = value
        self.level = level
        self.fval = fval
        
   
    # The function generates the children of the parent by moving the zero(0) elememnt in the feasible postion
    # There are 4 possible moves : left,up,right,down
   
    def generate_children(self):

        x,y = self.search_space(self.value,'0')
        coor_list = [[x,y-1],[x,y+1],[x-1,y],[x+1,y]]
        children = []
        for i in coor_list:
            child = self.valid_position(self.value,x,y,i[0],i[1])
            if child is not None:
                child_node = State(child,self.level+1,0)
                children.append(child_node)
                
        return children
      
   
    # Function searches for the position of the specific element in our case it is zero(0)
    
    
    def search_space(self,puz,x):
        for i in range(0,len(self.value)):
            for j in range(0,len(self.value)):
                if puz[i][j] == x:
                    return i,j
                  
    
    # Checks for the valid position of the zero(0) element and returns it.
    
    
    def valid_position(self,puz,x1,y1,x2,y2):
        
        if x2 >= 0 and x2 < len(self.value) and y2 >= 0 and y2 < len(self.value):
            temp_puz = []
            temp_puz = self.copy_matrix(puz)
            temp = temp_puz[x2][y2]
            temp_puz[x2][y2] = temp_puz[x1][y1]
            temp_puz[x1][y1] = temp
            return temp_puz
        else:
            return None
        
        
    # Makes the copy of matrix
    
    
    def copy_matrix(self,root):

        temp = []
        for i in root:
            t = []
            for j in i:
                t.append(j)
            temp.append(t)
        return temp    

class Eight_Puzzle:
    
    
    # Initializing the Eight Puzzle by the given size, fringe and explored list
  
    
    def __init__(self,size):
        self.n = size
        self.fringe = []
        self.explored = []
        
    
    # Accepts values for Initial and Goal state from user
  
    
    def get_values(self):
            create_matrix = []
            for i in range(0,self.n):
                store_value = input().split(",")
                create_matrix.append(store_value)
            return create_matrix
        
    
    # Function calculates the misplaced tiles(values) between the Initial and Goal state
    
    
    def h_misplaced_tiles(self,initial_state,goal_state):
            mis_tiles = 0
            for i in range(0,self.n):
                for j in range(0,self.n):
                    if initial_state[i][j] != goal_state[i][j] and initial_state[i][j] != '0':
                        mis_tiles += 1

            return mis_tiles
    
    
    
    ##############################################
    # It calculates the sum of hueristic value 
    # f(x) = g(x) + h(x)
    # g(x) = level order
    # h(x) = manhattan distance or misplaced tiles
    ##############################################
    
    
    def f_misplace_tiles(self,initial_state,goal_state):
        g_x = initial_state.level
        h_x = self.h_misplaced_tiles(initial_state.value,goal_state)
        f_x = g_x + h_x
        print("\ng(x): ",g_x)
        print("h(x): ",h_x)
        print("f(x): ",f_x)
        return f_x
    
    
    
    ########################################################################################
    # This function takes the Initial and Goal state from the user. 
    # Further it calls the other function to expand the children of parent to reach the goal
    # It also removes the current state node and adds to explored state
    # Finally it checks if the goal state is reached or not
    ########################################################################################
    def stage_process(self):
            counter = 0 
            print("\nInitial State \nEnter values comma separated 3 in each row(e.g: 1,2,3): ")
            initial_state = self.get_values()
            print("\nGoal State \nEnter values comma separated 3 in each row(e.g: 4,5,6): ")        
            goal_state = self.get_values()
           
            
            initial_state = State(initial_state,0,0)
            
            initial_state.fval = self.f_misplace_tiles(initial_state,goal_state)
            
            self.fringe.append(initial_state)
            print("\n\n")
            while True:
                
                cur = self.fringe[0]
                if counter == 0:
                    counter =1
                else:
                    print("")
                    print("  |  ")
                    print("  |  ")
                    print("  |  ")
                    print(" \\/ \n")
                    
                for i in cur.value:
                    for j in i:
                        print(j,end=" ")
                    print("")
                
                
                if(self.h_misplaced_tiles(cur.value,goal_state) == 0):
                    break
                        
                print("\nBelow are the values of all the child nodes that are added to the fringe but will expand the node with minimum value of f(x): ")
                for i in cur.generate_children():
                    
                    i.fval = self.f_misplace_tiles(i,goal_state)
                        
                    self.fringe.append(i)
                    
                self.explored.append(cur)
                del self.fringe[0] 
                
                self.fringe.sort(key = lambda x:x.fval,reverse=False)

            


obj = Eight_Puzzle(3)
obj.stage_process()


'''
4,1,3
0,2,6
7,5,8

1,2,3
4,5,6
7,8,0

'''
