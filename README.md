# server_client
**Репозиторий для курсовой работы**

**s.s** - Файл с сервером

**test.c** - Файл, в котором я пытался парсить строки


Компиляция: 
>gcc s.c -o s


Использование:
>./s


Сервер запускается с адресом: 
>http://localhost:8080


В роли клиента выступает браузер. При посещении открывается страница авторизации. Пользователь указывает авторизационный токен. 

По умолчанию значение токена:
>token = my_token

Также можно указать значение параметров. Любое указанное значение сервер запишет сохранит как значение параметра. В случае, если необходимо просмотреть текущее установленное значение, в поле параметра необходимо передать значение:
>\_\_inspect


При получении такого параметра и, если был передан корректный токен, сервер покажет текущее установленное значение параметра, не изменив его.
