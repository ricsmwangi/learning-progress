#include <microhttpd.h>
#include <stdio.h>
#include <string.h>

#define PORT 8888

enum MHD_Result answer(void *cls, struct MHD_Connection *connection,
                       const char *url, const char *method,
                       const char *version, const char *upload_data,
                       size_t *upload_data_size, void **con_cls)
{
    const char *page = "<html><body><h1>This is a FishThin WebApp</h1><p>Made with pure C!For Kanyua!!\nWait till its finished!!</p></body></html>";
                       //"<html><body<><h2><p>Wait till its finishe!!!<h2></p></body></html>";
    struct MHD_Response *response;
    enum MHD_Result ret;

    response = MHD_create_response_from_buffer(strlen(page),
                    (void*) page, MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_INTERNAL_POLLING_THREAD, PORT,
                              NULL, NULL, &answer, NULL, MHD_OPTION_END);
    if (NULL == daemon) {
        printf("Failed to start web server.\n");
        return 1;
    }

    printf("This is your !Fish WebApp running at http://localhost:%d\n, Wait till its finished!!\n\n", PORT);
    printf("Press Enter to stop.\n");
    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}
