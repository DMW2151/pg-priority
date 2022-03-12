CREATE OR REPLACE FUNCTION deprioritize_cpu(int) 
    RETURNS boolean AS 'MODULE_PATHNAME','deprioritize_cpu'
LANGUAGE C STRICT;

CREATE OR REPLACE FUNCTION deprioritize_io(int) 
    RETURNS boolean AS 'MODULE_PATHNAME','deprioritize_io'
LANGUAGE C STRICT;