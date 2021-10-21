class Bank:

    def __init__(self, balance: List[int]):
        self.q = [i for i in balance]
        self.n = len(self.q)

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        a1 = account1 -1
        a2 = account2 -1
        if a1 < 0 or a1 >=self.n or a2 <0 or a2 >=self.n:
            return False
        if self.q[a1] >= money:
            self.q[a2] += money
            self.q[a1] -= money
            return True
        return False

    def deposit(self, account: int, money: int) -> bool:
        a = account -1
        if a < 0 or a >=self.n:
            return False
        self.q[a] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        a = account -1
        if a < 0 or a >=self.n:
            return False
        if self.q[a] >= money:
            self.q[a] -= money
            return True
        return False

# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
