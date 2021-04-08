from sys import stdout,stdin

def GCD(x, y):  
    while(y): 
        x, y = y, x % y 
    return x 


t = int(stdin.readline())

while t != 0:
    s = input()
    punto = False
    abajo =  1
    fraccion = 0
    entero = 0

    for c in s:
        if c == '.':
            punto = True
            continue
        
        if punto == False:
            entero = entero * 10 + int(c)
        else:
            fraccion = fraccion * 10 + int(c)
            abajo =  abajo * 10
    

    arriba = abajo * entero + fraccion
    k = [0,1,2,3,4,5,6,7, 8]
    #k = []
    #for x in range(1000000):
    #    k.append(x)

    indices = [-1, 0, 1, 2, 3, 4, 5, 6]
    #indices = [0, 1, 2, 3, 4, 5, 6]
    k[-1] = arriba // abajo
    #residuos[-1] = arriba % abajo

    x = -1
    #while abajo != 0:
    while x<7:
        #print (arriba, abajo)
        k[x] = arriba // abajo
        #residuo = abajo
        residuo = arriba
        #residuo = arriba // abajo
        #residuo = arriba % abajo

        #residuos[x] = k[x-1] % residuos[x-1]
        #residuo = arriba
        arriba = arriba % abajo
        #residuo = arriba
        h = arriba
        arriba = abajo
        abajo = h
        x = x + 1
    x = x - 1
    #print (x)
    #k[7] = 0
    #k[7] = residuo

    #for w in k:
    #    print(w ),
    #print (k)
    #str1 = ''.join(str(e) for e in k)
    #stdout.write(str1 + '\n')
    #print()
    m0 = k[x - 1] * k[x] + 1
    m1 = k[x - 2] * m0 + k[x]
    x = x - 3
    while x>0:
        m00 = k[x] * m1 + m0
        #m11 = k[x] - 1
        m0 = m1
        m1 = m00
        


        x = x - 1

    #m = k[6] * k[7] + 1
    #m1 = k[5] * m + k[7]
    #m2 = k[4] * m1 + m
    #m3 = k[3] * m2 + m1
    #m4 = k[2] * m3 + m2
    #m5 = k[1] * m4 + m3
    a = k[-1] * ( k[0] * m1 + m0 ) + m1
    b = k[0] * m1 + m0

    #print ("%d")
    g = GCD(a, b)

    stdout.write(str(k[-1]))
    for i in range(7):
        stdout.write(' ' + str(k[i]))
    stdout.write('\n')
    #str1 = ''.join(str(e) for e in k)
    #stdout.write(str1 + '\n')
    stdout.write(str(a//g) + '/' + str(b//g) + '\n')

    t = t - 1
