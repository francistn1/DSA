from sortedcontainers import SortedList
class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.store = defaultdict(int)
        self.films = defaultdict(SortedList)
        self.rental = set()

        for shop, movie, price in entries: # find movie list
            self.store[(shop, movie)] = price
            self.films[movie].add((price, shop))

    def search(self, movie: int) -> List[int]:
        return list(map(lambda x: x[1], self.films[movie][:5])) # finds cheapest 5 shops that have an unrented copy of a given movie. The shops should be sorted by price in ascending order

    def rent(self, shop: int, movie: int) -> None:
        price = self.store[(shop, movie)] #find price
        self.films[movie].discard((price, shop)) # find movie, discard from movie list
        self.rental.add((price, shop, movie)) # add to our list
        return 

    def drop(self, shop: int, movie: int) -> None:
        price = self.store[(shop, movie)] #find price
        self.films[movie].add((price, shop)) # find movie that we added
        self.rental.discard((price, shop, movie)) # discard from list
        return

    def report(self) -> List[List[int]]:
        report_stores = sorted(self.rental)[:5]
        return list(map(lambda x: (x[1], x[2]), report_stores))


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()