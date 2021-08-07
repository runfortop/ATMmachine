# ATMmachine
Simple ATM machine control code


## ● code execution description

**1. Input card**

The initial screen is shown below.
The ATM Machine is waiting to confirm that the card has been inserted. Please select 1 if the card is fully inserted.

```
Welcome to ATM machine!
Please insert card
1. Yes, 2. NO =>_
```

**2. Input Pin number**
This is the procedure to receive a PIN number after card insertion is completed.
The set pin number is 9999.
It keeps asking for input until you enter the correct pin number, and if you want to return to the initial screen again, just enter 99.

---
Please enter your pin number
If you want to quit, enter 99
num :_
---

**3. Choose account**
After entering the pin number, the bank account associated with the card is displayed and you can select the account you want to trade with.

---
Please Choose your acount

1. acount number : 1111
2. acount number : 2222
3. acount number : 3333
If you want to quit, enter 99
num :_
---

**4. Choose transaction**
You can proceed with the transaction by selecting deposit, withdrawal, or balance check from the selected account.
Choose number 4 to end the transaction.

---
Choose the service you want!

1. Withdraw
2. Deposit
3. Balance
4. End
num :_
---

**5. Withdraw**
If you choose No. 1, enter the amount to be withdrawn as shown below.

---
Enter the withdrawal amount
100
---

If the account balance is insufficient, the following message will appear. Please make a deposit first and then withdraw. (The initial balance is 0 for all 3 accounts.)

---
You do not have enough money in your account.
Do you want to continue another transaction?
1. Continue, 2. End
num :_
---

**6. Deposit**
If you select deposit 2, you can enter the deposit amount as shown below.
When the deposit is completed, the current balance is notified.

---
Enter the deposit amount 
100

You have deposited 100 and your new balance is 100
Do you want to continue another transaction?
1. Continue, 2. End
num :_
---

**7. Balance**
If you select 3rd check balance, you will be informed of the balance status as shown below.

---
Your balance is 100
Do you want to continue another transaction?
1. Continue, 2. End
num :_
---

**8. End**
And if you select Exit from all menus, you will return to the initial card entry verification process.


