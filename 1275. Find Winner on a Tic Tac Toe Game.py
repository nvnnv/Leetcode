    def tictactoe(self, moves):
        grid = [[1 for i in range(0,3)] for i in range(0,3)]
        turn = 5 # 5 mean A  8 means B
        for i in moves:
            grid[i[0]][i[1]] = turn
            
            row1 = sum(grid[0])
            row2 = sum(grid[1])
            row3 = sum(grid[2])
            col1 = grid[0][0] + grid[1][0] + grid[2][0]
            col2 = grid[0][1] + grid[1][1] + grid[2][1]
            col3 = grid[0][2] + grid[1][2] + grid[2][2]
            diag1 = grid[0][0] + grid[1][1] + grid[2][2]
            diag2 = grid[1][1] + grid[2][0] + grid[0][2]
            
            if row1 == 15 or row2 == 15 or row3 == 15 or col1 == 15 or col2 == 15 or col3 == 15 or diag1 == 15 or diag2 == 15:
                return 'A'
            if row1 == 24 or row2 == 24 or row3 == 24 or col1 == 24 or col2 == 24 or col3 == 24 or diag1 == 24 or diag2 == 24:
                return 'B'

            if turn == 5:
                turn = 8
            else:
                turn = 5
        if len(moves) >= 9:
            return 'Draw'
        else:
            return 'Pending'
