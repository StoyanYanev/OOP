**Задача: Банкова система**         **общо 10 точки**

Да се напише програма, която моделира банкова система и операциите, които се извършват в нея.
 ![](data:image/*;base64,/9j/4AAQSkZJRgABAQAAAQABAAD/2wBDAAgGBgcGBQgHBwcJCQgKDBQNDAsLDBkSEw8UHRofHh0aHBwgJC4nICIsIxwcKDcpLDAxNDQ0Hyc5PTgyPC4zNDL/2wBDAQkJCQwLDBgNDRgyIRwhMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjL/wAARCAAsBXcDASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD3+iiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKAP//Z)

1.  Да се създаде клас **Customer** (потребител)        1 точка

Член-данни:

**id** –идентификатор на потребителя **name** –име на потребителя

**address** –адрес на потребителя

Методи:

конструктор с параметри

селектори: **getId** , **getName** , **getAddress**

**display** –извежда информация за потребителядопълнителни методи, ако е необходимо

2.  Да се създаде абстрактен клас **Account** (банкова сметка)        2 точки

Член-данни:

**iban** –номер на банкова сметка(IBAN)

**ownerId** –идентификатор на потребителя,собственик на банковата сметка **amount** –налична сума в сметката

Методи:

конструктор с параметри

чисто виртуален метод **deposit** – за добавяне на сума към банковата сметка

чисто виртуален метод **withdraw** – за изтегляне на сума от банковата сметка, ако това е възможно

(връща true или false)

чисто виртуален метод **display** – за извеждане на информация за сметката **getBalance** –връща наличната сума в сметката

допълнителни методи, ако е необходимо

3.  Да се създадат следните производни класове        3 точки

3.1. Клас **CurrentAccount** (текуща сметка)

Класът CurrentAccount наследява Account и реализира методите:

**deposit** –за добавяне на сума към банковата сметка

**withdraw** –за изтегляне на сума от банковата сметка.Ако в сметката има по-малко пари от исканата

сума, връща false, иначе – намалява сумата на сметката с исканата сума и връща true

**display** –за извеждане на информация за сметката–вид на сметка, IBAN,номер на потребител,

баланс допълнителни методи, ако е необходимо

3.2. Клас **SavingsAccount** (спестовна сметка)

Класът **SavingsAccount** наследява **Account** като го допълва с

**interestRate** –годишен лихвен процент

- и.реализира методите:

**getInterestRate** –връща годишния лихвен процент **deposit** –за добавяне на сума към банковата сметка

**withdraw** –за изтегляне на сума от банковата сметка.Ако в сметката има по-малко пари от исканата

сума, връща false, иначе – намалява сумата на сметката с исканата сума и връща true

**display** –за извеждане на информация за сметката–вид на сметка, IBAN,номер на потребител,

годишния лихвен процент, баланс допълнителни методи, ако е необходимо

3.3. Клас **PivilegeAccount** (привилегирована сметка)

Класът **PivilegeAccount** наследява **Account** като го допълва с

**overdraft** –позволен овърдрафт(сума превишаваща кредита)

- и.реализира методите:

**getOverdraft** –връща позволения овърдрафт

**deposit** –за добавяне на сума към банковата сметка

**withdraw** –за изтегляне на сума от банковата сметка.Ако наличната сума в сметката+позволенияовърдрафт е по-малко от исканата сума, връща false, иначе – намалява сумата на сметката с исканата сума и връща true (в този случай може да се получи отрицателно число за баланса)

**display** –за извеждане на информация за сметката–вид на сметка, IBAN,номер на потребител,

позволен овърдрафт, баланс допълнителни методи, ако е необходимо

4.  Да се създаде клас **Bank** (банка)        3 точки

Член-данни:

**name** –име на банката

**address** –адрес на банката

**customers** –списък от потребители(изберете подходящ начин за представяне) **accounts** –списък от банкови сметки(изберете подходящ начин за представяне)

Методи:

конструктор с параметри

селектори: **getName** , **getAddress**

**addCustomer** с параметриcustomerId, nameиaddress–ако не съществува потребител с

идентификатор customerId, създава нов потребител и го добавя към списъка с потребителите **listCustomers** –извежда списък с потребителите

**deleteCustomer** с параметърcustomerId–изтрива потребител с идентификаторcustomerIdот

списъка с потребители, както и всички негови сметки

**addAccount** с параметриaccountType, iban, ownerId, amount–създава нова сметка от съответниятип и я добавя към списъка с банкови сметки. Ако не съществува потребител с идентификатор

**ownerId** или съществува банкова сметка със същияIBAN–извежда съобщение за грешка. **deleteAccount** с параметърiban–изтрива сметка с съответенIBAN

**listAccounts** –извежда информация за всички сметки в банката

**listCustomerAccount** с параметърcustomerId–извежда информация за банковите сметки на

потребител с идентификатор customerId

**transfer** с параметриfromIBAN, toIBANиamount–извършва банков превод на сумаamountотбанкова сметка с идентификатор fromIBAN към банкова сметка с идентификатор toIBAN, ако е

възможно

**display** –извежда информация за банката и колко потребителя и сметки имадопълнителни методи, ако е необходимо

5.  Да се напише главна програма        1 точка

В главната програма да се създаде банка и да се реализира следното меню:

1. 1List customers
2. 2Add new customer
3. 3Delete customer
4. 4List all accounts
5. 5List customer accounts

1. 6Add new account
2. 7Delete account
3. 8Withdraw from account
4. 9Deposit to account
5. 10Transfer
6. 11Display info for the bank

1. 12Quit
