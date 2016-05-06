fline = 0
players = []
f = open('sample.txt')
for line in f:
	if fline == 0:
		fline = 1
		continue
	player = line[0]
	if player.isdigit():
		player = int(player) - 1
		players.append(player)
		
for v in players:
	print v