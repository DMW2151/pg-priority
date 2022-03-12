FROM postgres

RUN apt-get update -y &&\
    apt-get install -y \
        make \
        gcc \
        postgresql-server-dev-14

COPY ./prio/ ./prio/

RUN cd ./prio &&\
    make all &&\
    cp ./prio.control prio*.sql $(pg_config --sharedir)/extension &&\
    cp  ./*.so $(pg_config --pkglibdir)

ENTRYPOINT ["docker-entrypoint.sh"]

CMD ["postgres"]