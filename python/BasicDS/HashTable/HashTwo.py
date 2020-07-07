'''
    Hash Table 의 장단점

    장점
    1. 검색 속도가 O(1)
    2. key, value 1:1 매칭이므로, 기존 데이터가 존재하는지 바로 확인 할 수 있기 때문에, 
    중복 처리/확인 이 쉽다.

    단점
    1. 다른 자료구조에 비해 저장공간이 다소 많이 필요
    (실제 저장하는 데이터 양에 비해서 전체 데이터 크기가 크기 때문에
    안쓰는 주소값이 반드시 생겨서 주소 낭비가 생김)
    2. key 에 여러개의 value 가 매칭되면 이에 따른 별도의 처리가 필요

    주 용도
    1. 검색
    2. CRUD 를 자주 할 때
    3. Cache 구현 (중복 확인 용도)
'''

# 연습 1. 리스트 변수를 이용하여 해쉬 테이블 구현
# 파이썬 내부적으로 hash 함수를 제공하긴함, 근데 재 실행 할 때마다 매번 값이 바뀜

hash_table = list([0 for i in range(10)])


def get_key(data):
    return hash(data)


def hash_func(key):
    return key % 8


def save_data(data, value):
    key = get_key(data)
    hash_address = hash_func(key)
    hash_table[hash_address] = value


def read_data(data):
    key = get_key(data)
    hash_address = hash_func(key)
    return hash_table[hash_address]


save_data('park', '2017110272')
save_data('kim', '2018111277')
print(read_data('park'))
