FROM alpine:3.16.2

RUN apk add dpkg curl wget alpine-sdk boost-dev && dpkg --add-architecture amd64 && cd ~/

COPY ./app /root/src/app

WORKDIR /root/src

RUN curl -s https://api.github.com/repos/CrowCpp/Crow/releases/latest \
| grep "browser_download_url.*deb" \
| cut -d : -f 2,3 \
| tr -d \" \
| wget -qi -

RUN dpkg -i *.deb && rm -rf *.deb
RUN g++ app/main.cpp -lpthread

EXPOSE 18080

ADD /templates ./templates
ADD /assets ./assets

CMD ["./a.out"]

