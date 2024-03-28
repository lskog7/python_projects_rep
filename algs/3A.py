def find_common_songs(num_people, playlists):
    common_songs = set(playlists[0][1])
    for i in range(1, num_people):
        common_songs.intersection_update(playlists[i][1])
    return sorted(common_songs) 
num_people = int(input())
playlists = []
for _ in range(num_people):
    num_tracks = int(input())
    tracks = input().split()
    playlists.append((num_tracks, set(tracks)))

result = find_common_songs(num_people, playlists)

print(len(result))
print(*result)
