class Stack:
    # jumlah_tumpukan = 0
    def __init__(self):
        self._data = [3, 1]
        # Stack.jumlah_tumpukan += 1

    def array(self):
        return [data for data in self._data]

    def length(self):
        return len(self._data)

    def isEmpty(self):
        return len(self._data) == 0

    def push(self, item):
        self._data.append(item)
        print(f"{item} ditambahkan ke tumpukan")

    def pop(self):
        if self.isEmpty() == True:
            print("Tidak bisa pop. List kosong")
            return None
        print(f"{self._data[-1]} dikeluarkan dari tumpukan")
        max = len(self._data)
        self._data[:] = self._data[:max-1]
        # self._data[:] = self._data[1:max] for queue

Tumpukan = Stack()
while True:
    print()
    print("size:", Tumpukan.length())
    print(Tumpukan.array())
    print("What you want to do?")
    print("1: push")
    print("2: pop")
    print("3: cek array kosong")
    print("4: exit")
    pilihan = int(input("Masukkan pilihan: "))

    if (pilihan == 1):
        elemen = int(input("Masukkan angka yang ingin dimasukkan ke dalam tumpukan: "))
        Tumpukan.push(elemen)
    elif (pilihan == 2):
        Tumpukan.pop()
    elif (pilihan == 3):
        print("apakah array kosong?", Tumpukan.isEmpty())
    elif (pilihan == 4):
        break
    else:
        print("masukkan angka opsi antara 1, 2, 3, atau 4\n")




"""
class Node():

    node_list = []
    next_id = 1

    def __init__(self, state, parent, action):
        self.id = Node.next_id
        self.state = state
        self.parent = parent
        self.action = action # child

        Node.next_id += 1
        Node.node_list.append(self.id)


class StackFrontier():
    def __init__(self):
        self.frontier = []

    @property
    def frontier_list(self):
        # return [(frontier.state, frontier.action) for frontier in self.frontier] # state and the child, computationally expensive. I only use this for the small data
        return [frontier.state for frontier in self.frontier] # just state

    def add(self, node):
        self.frontier.append(node)
        # print(node, 'appended!')

    def contains_state(self, state):
        return any(node.state == state for node in self.frontier)

    def empty(self):
        return len(self.frontier) == 0

    def remove(self):
        if self.empty():
            raise Exception("empty frontier")
        else:
            node = self.frontier[-1]
            self.frontier = self.frontier[:-1]
            return node


class StackFrontier(StackFrontier):

    def remove(self):
        if self.empty():
            raise Exception("empty frontier")
        else:
            node = self.frontier[0]
            self.frontier = self.frontier[1:]
            return node
"""