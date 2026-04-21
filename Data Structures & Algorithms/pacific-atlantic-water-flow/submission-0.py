class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:

        # so basically the idea here is we want to do a BFS on all top and left cells
        # we can have a queue for the cells we have yet to traverse
            # append only if the height is equal or lesser
        # we can have a result arr for all the resulting paths

        
        ROWS = len(heights)
        COLS = len(heights[0])

        pacific_queue = deque()
        atlantic_queue = deque()
        result = []

        pacific_visited = set() # ensure we dont visit the same pos twice

        atlantic_visited = set() # ensure we dont visit the same pos twice

        directions = [[0,1], [1, 0], [-1, 0], [0, -1]]

        #initialization of queue
        for row in range(ROWS):
            pacific_queue.append((row, 0))
            pacific_visited.add((row,0))
        for col in range(COLS):
            if (0, col) not in pacific_visited:
                pacific_queue.append((0, col))
                pacific_visited.add((0, col))
        for row in range(ROWS):
            atlantic_queue.append((row, COLS - 1))
            atlantic_visited.add((row, COLS - 1))
        for col in range(COLS):
            if (ROWS - 1, col) not in atlantic_visited:
                atlantic_queue.append((ROWS - 1, col))
                atlantic_visited.add((ROWS - 1, col))
        def bfs(queue, visited):
            while queue:
                # path = []
                r, c = queue.popleft()
                # path.append((r, c))
                for dr, dc in directions:
                    new_r = r + dr
                    new_c = c + dc
                    if new_r < ROWS and new_r >=0 and new_c < COLS and new_c >=0 and (new_r, new_c) not in visited:
                        if heights[new_r][new_c] >= heights[r][c]:
                            queue.append((new_r, new_c))
                            visited.add((new_r, new_c))
            return visited
        return list(bfs(pacific_queue,pacific_visited) & bfs(atlantic_queue, atlantic_visited))
