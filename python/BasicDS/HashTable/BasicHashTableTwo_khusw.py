'''
    충돌 방지 함수
    hash 는 key 에 여러개의 value 가 들어와서 충돌(collision) 을 일으키는 경우가 있다.
    이를 개선하기 위한 근원적인 방법은 
    hash table 의 크기를 늘리는 것이 아니라, hash function 자체의 기능을 수정해야 한다.
    앞선 코드들에서는 hash function 이 매우 단순한 구조였다.
    이번 코드에서는 이를 어떻게 개선할지를 알아본다.

    collision 방지를 위한 두가지 주요 기법

    1. Chaining 
    개방 해시 또는 Open Hashing 기법 중 하나로, hash table 외의 저장공간을 생성하여 활용하는 기법
    충돌이 발생하면 linked list 를 이용해서 linked list 로 데이터를 추가하여 뒤에 연결시켜 저장하는 방법임

    2. Linear Probing 
    폐쇄 해시 또는 Close Hashing 기법 중 하나로 hash table 저장공간 안에서 충돌 문제를 해결하는 기법이다.
    충돌이 발생하면 hash address 의 다음 address 부터 맨 처음 나오는 빈 저장공간에 저장하는 기법이다.
'''

# 연습 2. chaining 기법을 통해서 충돌 해결 코드 구성
# HashTwo.py 에 작성한 코드를 기반으로 linked list 만 추가하면 됨
# chaining 기법을 사용하는 경우, 겹치는 value 가 발생했을때,
# 해당 key 에 추가적인 linked list node 를 붙여서 증가시키는 방식임
# 그래서 node 를 여러개 붙일때, 이를 구별하기 위해서는
# node 에 값을 넣을 때, 각 노드를 구별할 수 있는 index 값이 별도로 들어가야함.
hash_table = list([0 for i in range(8)])


def get_key(data):
    return hash(data)


def hash_func(data):
    return data % 8


def save_data(data, value):
    index_key = get_key(data)  # index_key 로 지정한 이유는 node 의 구분자를 두기 위함이다.
    hash_address = hash_func(index_key)
    if hash_table[hash_address] != 0:  # 0 이 아니란 것은 이미 데이터가 존재할 때
        for i in range(len(hash_table[hash_address])):  # 특정 key 의 모든 node 조사
            if hash_table[hash_address][i][0] == index_key:  # node 의 맨앞이 index_key 이면
                hash_table[hash_address][i][1] = value  # 그 뒤를 value 로 전환
                return
        # node 에 하나도 일치하는 index 가 없는 경우 노드 추가
        hash_table[hash_address].append([index_key, value])
    else:
        # 0 인 경우 이므로 아무런 데이터도 없는 경우
        hash_table[hash_address] = [[index_key, value]]

# node 를 추가하는 자료의 구조는 이렇게 구성됨
# key : index_key | value , index_key | value ....
# hash_table[hash_address] 는 key 값을 의미하고,
# hash_table[hash_address][i] 는 index_key | value 의 한 쌍에 대한 인덱스 번호를 의미하고,
# hash_table[hash_address][i][0] 은 index_key 를
# hash_table[hash_address][i][1] 은 value 를 의미한다.


def read_data(data):
    index_key = get_key(data)
    hash_address = hash_func(index_key)
    if hash_table[hash_address] != 0:
        for i in range(len(hash_table[hash_address])):
            if hash_table[hash_address][i][0] == index_key:
                return hash_table[hash_address][i][1]
        return None
    else:
        return None


save_data('Dd', '1234')
save_data('Data', '3333')
print(read_data('Dd'))
print(hash_table)

# 연습 3. Linear Probing 기법으로 충돌 해결 코드를 구현
