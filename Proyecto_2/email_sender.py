import sys
import os
import smtplib
from email.message import EmailMessage

EMAIL_ADDRESS = os.environ.get('EMAIL_USER') # Se obtiene el correo electrónico del usuario desde las variables de entorno
EMAIL_PASSWORD = os.environ.get('EMAIL_PASS') # Se obtiene la contraseña del correo electrónico del usuario desde las variables de entorno

#NOTAS:
# 1. Para que el programa funcione, se debe tener una cuenta de gmail y habilitar el acceso a aplicaciones poco seguras
# 2. Se debe tener en cuenta que el correo electrónico del usuario y la contraseña del correo electrónico del usuario se deben guardar en las variables de entorno
# 3. Se debe tener en cuenta que el programa recibe 3 argumentos desde la consola: el asunto del correo, el contenido del correo y la ruta del archivo a adjuntar
# 4. Se debe tener en cuenta que el programa se debe ejecutar desde la consola con el siguiente comando: python email_sender.py <asunto> <contenido> <ruta del archivo a adjuntar>
# 5. Se debe pasar el filepath en c++  siguiendo el formato "../<Relative_path>"
def emailSender(_subject , _content, _filepath):
    msg = EmailMessage()
    msg['Subject'] = _subject
    msg['From'] = EMAIL_ADDRESS
    msg['To'] = '' # Se debe ingresar el correo electrónico del destinatario
    msg.set_content(_content)

    with open(_filepath, 'rb') as f:
        file_data = f.read()
        file_type = f.name.split('.')[1]
        file_name = os.path.basename(f.name)

    msg.add_attachment(file_data, maintype='application', subtype=file_type, filename=file_name)

    with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
    # smtp.ehlo() # Identifica el servidor de correo gmail
    # smtp.starttls() # Encripta la conexión con el servidor
    # smtp.ehlo() # Identifica el servido de correo gmail nuevamente para la conexión encriptada
        smtp.login(EMAIL_ADDRESS, EMAIL_PASSWORD) # Inicia sesión en el servidor de correo electrónico

        smtp.send_message(msg) # Envía el correo electrónico
    print('Correo enviado con exito') # Se imprime en consola que el correo fue enviado con éxito

if __name__ == '__main__':
    emailSender(sys.argv[1], sys.argv[2], sys.argv[3]) # Se ejecuta la función emailSender con los argumentos pasados por consola