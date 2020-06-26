'''
    list 를 이용한 python 의 Array
'''

# 1차원 배열
OneD = [1, 2, 3, 4, 5]

# 2차원 배열
TwoD = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# 기본연습
# 9,8,7 출력

for i in range(len(TwoD) - 1, -1, -1):
    print(TwoD[2][i])

# 기본 연습 2
# 아래의 dataset 에서 대문자 M 이 몇번 나오는지 출력
dataset = ['Braund, Mr. Owen Harris',
           'Cumings, Mrs. John Bradley (Florence Briggs Thayer)',
           'Heikkinen, Miss. Laina',
           'Futrelle, Mrs. Jacques Heath (Lily May Peel)',
           'Allen, Mr. William Henry',
           'Moran, Mr. James',
           'McCarthy, Mr. Timothy J',
           'Palsson, Master. Gosta Leonard',
           'Johnson, Mrs. Oscar W (Elisabeth Vilhelmina Berg)',
           'Nasser, Mrs. Nicholas (Adele Achem)',
           'Sandstrom, Miss. Marguerite Rut',
           'Bonnell, Miss. Elizabeth',
           'Saundercock, Mr. William Henry',
           'Andersson, Mr. Anders Johan',
           'Vestrom, Miss. Hulda Amanda Adolfina',
           'Hewlett, Mrs. (Mary D Kingcome) ',
           'Rice, Master. Eugene',
           'Williams, Mr. Charles Eugene',
           'Vander Planke, Mrs. Julius (Emelia Maria Vandemoortele)',
           'Masselmani, Mrs. Fatima',
           'Fynney, Mr. Joseph J',
           'Beesley, Mr. Lawrence',
           'McGowan, Miss. Anna "Annie"',
           'Sloper, Mr. William Thompson',
           'Palsson, Miss. Torborg Danira',
           'Asplund, Mrs. Carl Oscar (Selma Augusta Emilia Johansson)',
           'Emir, Mr. Farred Chehab',
           'Fortune, Mr. Charles Alexander',
           'Dwyer, Miss. Ellen "Nellie"',
           'Todoroff, Mr. Lalio']


cnt = 0
for data in dataset:
    for j in range(len(data)):
        if(data[j] == 'M'):
            cnt += 1

print(cnt)

'''
    다시 정리해보는 python 기본 문법
    range(10) : 0 ~ 9 까지
    range(1, 11) : 1 ~ 10 까지
    range(0, 20, 2) : 0 ~ 19 까지 하되 2씩 증가 (홀수는 안나옴) 
    0 2 4 6 .... 18
'''
