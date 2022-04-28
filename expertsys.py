from numpy import append

print('\n\n---------------Covid-19 Diagnosis Expert System-----------------\n\n')

symp=[]
symp_count=0
severity=0



def ques():
    s=''
    i=int(0)
    global severity

    # Mild symptoms Severity:-1

    print('How many symptoms do you have from following list:-\n(sore throat,headache,body ache,diarrhoea,rashes on skin,red eyes)?')
    i=int(input("> "))
    severity=i
    symp_count=i

    #serious Symptoms Severity:-2 (And additional inc in some cases)

    print('Do you have fever?(y/n)')
    s=input("> ")
    if(s=='y'):
        symp.append('fever')
        severity+=2
        symp_count+=1
        print('\tFrom how many days you have fever?')
        i=int(input("\t> "))
        if(i>7):
            severity+=1



    print('Do you have cough?(y/n)')
    s=input("> ")
    if(s=='y'):
        symp.append('cough')
        severity+=2
        symp_count+=1
        print('\tDry cough or wet cough(1/2)?')
        i=int(input("\t> "))
        if(i==1):
            severity+=1



    print('Do you feel tired frequently?(y/n)')
    s=input("> ")
    if(s=='y'):
        symp.append('tiredness')
        severity+=2
        symp_count+=1
        print('\tHow frequent in a day do you feel so?')
        i=int(input("\t> "))
        if(i>8):
            severity+=1

    print('Do you have lost of taste?(y/n)')
    s=input("> ")
    if(s=='y'):
        symp.append('loss of taste')
        severity+=2
        symp_count+=1

    #Very Serious Symptoms Severity:-3/4

    print('Do you feel difficulty breathing or shortness of breath?(y/n)')
    s=input("> ")
    if(s=='y'):
        symp.append('breathing difficulty')
        severity+=3
        symp_count+=1

    print('Do you feel loss of speech or mobility, or confusion?(y/n)')
    s=input("> ")
    if(s=='y'):
        symp.append('loss of speech/mobility/confusion')
        severity+=3
        symp_count+=1


    print('Do you have chest pain?(y/n)')
    s=input("> ")
    if(s=='y'):
        symp.append('chest pain')
        severity+=4
        symp_count+=1


def report():
    print("Total Severity coeff:-",severity)
    print('\n\nYou have following symptoms:-\n')
    for k in symp:
        print("->",k)
    print()

    #Very Serious condition
    
    if(severity>=15):
        print("Diagnosis:-There are very high chances that you are covid +ve")
        print("Precautions:- Isolate Yourself, Get RTPCR test done")
        print("Advise:-Refer your case to a doctor as soon as possible and follow the procedure you may need to get hospitalize so be prepared")

    
    #Moderate Condition
    
    elif(severity<15 and severity>=10):
        print("Diagnosis:-There are high chances that you are covid positive but not much serious")
        print("Precautions:- Isolate Yourself, Get RTPCR test done")
        print("Advise:-Refer your case to a doctor on phone and follow the procedure ")
    
    
    elif(severity<10 and severity>=5):
        print("Diagnosis:-There are slight chances that you are covid positive")
        print("Precautions:- Isolate Yourself, Get RTPCR test done")
        print("Advise:-Manage the symptons at home nothing much serious")
    
    #Normal Condition
    
    elif(severity<5):
        print("Diagnosis:-You are most probably not affected by covid")
        print("Advise:-Take general medicines if you have any mild symptoms")
    
    print("\n\n")



ques()
report()
        
    


        
    

    
    
