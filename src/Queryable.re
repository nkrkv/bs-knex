[@bs.send.pipe: KnexTypes.knex(_)] external toString : string = "";

module Make = (M: Builder.Builder) => {
    let toString = (builder) =>
        M.finish(builder)
        |> toString;

    let execute = (builder: M.t('a)): Js.Promise.t('a) =>
        M.finish(builder)
        |> Obj.magic
        |> Js.Promise.resolve;
};
