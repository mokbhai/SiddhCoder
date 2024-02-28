FROM node:21

WORKDIR /../app

COPY . .

RUN npm install

RUN pwd

COPY /test/entrypoint.sh /usr/src/app/test/entrypoint.sh
RUN chmod +x /usr/src/app/test/entrypoint.sh

ENTRYPOINT ["/usr/src/app/test/entrypoint.sh"]
