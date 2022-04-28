from datetime import datetime,date

msg=''
def  tourreply(msg):
    msg=msg.lower()
    if 'summer' in msg:
        reply='The recommended destinations for summer season are spiti leh-ladhak manali guwahati......'
    elif 'winter' in msg:
        reply='The recommended destinations for winter season are udaipur jaipur goa kerla.........'
    elif 'rainy' in msg or 'monsoon' in msg:
        reply='The recommended destinations for rainy  season are lonawala mahabaleshwar igatpuri.......'
    elif 'expenditure' in msg or 'cost' in msg or 'budget' in msg:
        reply="""The expenditure for the summer trip can vary from 15-20 thousand per person 
                The expenditure for the winter trip can vary from 20-25 thousand per person 
                The expenditure for the monsoon trip can vary from 10-15-15 thousand per person  """
    elif 'discount' in msg or 'offers' in msg:
        reply="Yes we have exciting offers on various packages to know more you can call our customer care number 111-9999-333 "
    elif 'book' in msg :
        reply='Please visit www.makemytrip.com to book hotels and tickets online'
    
    else:
        reply='For more details you can visit www.makemytrip.com'
    return reply

def getreplyregular(msg):
    msg=msg.lower()
   
    if 'who' in msg and 'you' in msg:
        reply="Hey, I am chatter...!!!!!!!"
    elif 'weather' in msg and 'today' in msg:
        reply="Its sunny today..."
    elif 'joke' in msg:
        reply='What do you call an ant who fights crime? A vigilANTe!'
    elif 'time' in msg and 'now' in msg:
        now = datetime.now()
        current_time = now.strftime("%H:%M:%S")
        reply="Time right now is : {0}".format(current_time)
    elif 'date' in msg and "today's" in msg:
        today = date.today()
        dt = today.strftime("%B %d, %Y")
        reply="Today's date is : {0}".format(dt)
    else:
        reply='please ask something else..'
    
    return reply
    

while(1):
    msg=input('You: ')
    
    if 'tourist' in msg and 'destination' in msg:
        while(1):

            msg=input('You: ')
            if 'thanks' in msg:
                print("Bot: My Pleasure")
                break
            rep=tourreply(msg)
            print("Bot: ",rep)
            
           
        continue

    if "bye" in msg:
        print("Bot: It was nice talking to you have a great day Byeeeee !!!!!")
        break
     
    rep=getreplyregular(msg)
    print("Bot: ",rep)
    

