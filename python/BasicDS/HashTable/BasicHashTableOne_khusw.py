'''
    해쉬 테이블

    Hash Table 은 Key 에 Value 를 저장하는 테이블 구조로,
    Key 를 통해서 바로 데이터를 받아올 수 있는 구조임.
    (배열은 순차 탐색을 통해서 가져오지만
    Hash Table 은 hash function 을 통해서 바로 값 찾기가 가능)
    Python 의 Dictionary 가 Hash Table 을 이용한 형태

    용어
    Hash : 어떤 임의의 값을 주면 hash function 을 통해서 고정해놓은 길이로 변경하는 것.
    Hash Table : Key, Value 로 구성된 데이터 구조
    Hashing function : Key 에 대해 어떤 연산을 이용해서 데이터를 찾는 함수
    Hash Value or Hash Address : Key 를 hashing function 을 통해서 연산한 후
    hash 값을 알아내서 이를 기반으로 지정한 주소 값
    
    slot : 한 개의 데이터를 저장할 수 있는 공간
    저장한 데이터에 대해서 key를 추출할 수 있는 별도의 함수도 존재.


'''

hash_table = list([i * i for i in range(10)])
print(hash_table)

'''
    hash_func 는 아주 간단한 hash function 예시.
    나누기를 통해서 나머지를 기반으로 키 값을 생성해줌
'''


def hash_func(key):
    return key % 5  # key 값을 5로 나눈 나머지 값 리턴


'''
    ord() 는 각 문자의 ascii 값을 리턴하는 함수로 built-in function 이다.
    아래에 3개의 데이터를 생성하고 ord 를 이용해서 임의의 키를 만들어 본다
'''
data1 = 'andy'
data2 = 'tom'
data3 = 'sim'

print(ord(data1[0]), ord(data2[0]), ord(data3[0]))
print(ord(data1[0]), hash_func(ord(data1[0])))
# 아스키 코드 값 그대로는 키 값으로 쓰기엔 값이 너무 크므로 앞서 만든 hash_func 을 이용해 hash address 생성


def storage_data(data, value):
    key = ord(data[0])
    hash_address = hash_func(key)
    hash_table[hash_address] = value
# key, value 를 이용해서 hash_table 갱신


storage_data(data1, '01012345678')
storage_data(data2, '01023456789')
storage_data(data3, '01034567891')

print(hash_table)


def get_data(data):
    key = ord(data[0])
    hash_address = hash_func(key)
    return hash_table[hash_address]
# key 를 넣었을 때 value 를 리턴하는 함수


print(get_data(data1))


# 문법 참조 : https://mingrammer.com/introduce-comprehension-of-python/
