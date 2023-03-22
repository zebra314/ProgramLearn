import csv
edgeFile = 'edges.csv'


def bfs(start, end):
    #　Implement a bfs algorithm
    #　Input: start, end
    #　Output: path, dist, num_visited
    num_visited = 0
    path = []
    dist = 0
    with open('/home/alfonso/Git_workspace/ProgramLearn/intro_to_ai/HW2/AI_HW2/edges.csv', 'r') as f:
        reader = csv.reader(f)
        next(reader)
        for row in reader:
            if int(row[0]) == start:
                num_visited += 1
                path.append(int(row[0]))
                if int(row[1]) == end:
                    num_visited += 1
                    path.append(int(row[1]))
                    dist += float(row[2])
                    break
                else:
                    dist += float(row[2])
                    start = int(row[1])

    
    return path, dist, num_visited
    # Begin your code (Part 1)
    # raise NotImplementedError("To be implemented")
    # End your code (Part 1)


if __name__ == '__main__':
    path, dist, num_visited = bfs(2270143902, 1079387396)
    print(f'The number of path nodes: {len(path)}')
    print(f'Total distance of path: {dist}')
    print(f'The number of visited nodes: {num_visited}')


