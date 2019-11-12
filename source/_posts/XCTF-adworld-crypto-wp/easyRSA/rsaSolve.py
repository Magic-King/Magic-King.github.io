
'''
def gcd(a,b):
	return b if a%b==0 else gcd(b,a%b)
	
def mod_inverse(a,mod):
'''

def EX_GCD(a,b,arr): #扩展欧几里得
    if b == 0:
        arr[0] = 1
        arr[1] = 0
        return a
    g = EX_GCD(b, a % b, arr)
    t = arr[0]
    arr[0] = arr[1]
    arr[1] = t - int(a / b) * arr[1]
    return g

	
def ModReverse(a,n): #ax=1(mod n) 求a模n的乘法逆x
    arr = [0,1,]
    gcd = EX_GCD(a,n,arr)
    if gcd == 1:
        return (arr[0] % n + n) % n
    else:
        return -1

'''
while True:
	a,b = eval(input())
	print(ModReverse(a,b))
'''

if __name__=='__main__':
	while True:
		l = input("p,q,e:")
		p,q,e = map(lambda x:int(x),l.split(","))
		fn = (p-1)*(q-1)
		#print(l)
		d = ModReverse(e,fn)
		print("d=%d"%d)
				
	
	
	
	
	
