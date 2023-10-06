class Twitter:

    def __init__(self):
        self.posts = {}
        self.follower = {}
        self.timestamp = 0
        
    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.posts:
            self.posts[userId] = []        
        self.posts[userId].append((self.timestamp, tweetId))
        self.timestamp += 1     

    def getNewsFeed(self, userId: int) -> List[int]:
        if userId in self.posts and userId in self.follower:
            users = self.follower[userId] + [userId]
        elif userId in self.posts:
            users = [userId]
        elif userId in self.follower:
            users = self.follower[userId]
        else:
            return []
        heap = []
        feed = []
        for user in users:
            if user in self.posts:
                for timestamp, tweetId in self.posts[user]:
                    heapq.heappush(heap, (-timestamp, tweetId))
        while heap and len(feed) < 10:
            timestamp, tweetId = heapq.heappop(heap)
            feed.append(tweetId)
        return feed

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.follower:
            self.follower[followerId] = []
        if followeeId not in self.follower[followerId]:
            self.follower[followerId].append(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.follower and followeeId in self.follower[followerId]:
            self.follower[followerId].remove(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)