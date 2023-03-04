import sys

_input = lambda : sys.stdin.readline()

n, m = map(int, _input().split())

graph = {}

for i in range(n):
    line = map(int, _input().split())
    graph[i] = line[1:]

print(graph)
