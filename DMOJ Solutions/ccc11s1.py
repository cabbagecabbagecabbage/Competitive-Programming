t = 0
s = 0
for i in range(int(input())):
    st = input().lower()
    t += st.count("t")
    s += st.count("s")
if s>= t:
    print("French")
else:
    print("English")